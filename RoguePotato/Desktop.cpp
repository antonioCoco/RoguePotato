
#include <windows.h>
#include "Desktop.h"
BOOL AddTheAceWindowStation(HWINSTA hwinsta, PSID psid)
{

	ACCESS_ALLOWED_ACE* pace=NULL;
	ACL_SIZE_INFORMATION aclSizeInfo;
	BOOL                 bDaclExist;
	BOOL                 bDaclPresent;
	BOOL                 bSuccess = FALSE; // assume function will
											//fail
	DWORD                dwNewAclSize;
	DWORD                dwSidSize = 0;
	DWORD                dwSdSizeNeeded;
	PACL                 pacl;
	PACL                 pNewAcl=NULL;
	PSECURITY_DESCRIPTOR psd = NULL;
	PSECURITY_DESCRIPTOR psdNew = NULL;
	PVOID                pTempAce;
	SECURITY_INFORMATION si = DACL_SECURITY_INFORMATION;
	unsigned int         i;

	__try
	{
		if (!GetUserObjectSecurity(
			hwinsta,
			&si,
			psd,
			dwSidSize,
			&dwSdSizeNeeded
		))
			if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
			{
				psd = (PSECURITY_DESCRIPTOR)HeapAlloc(
					GetProcessHeap(),
					HEAP_ZERO_MEMORY,
					dwSdSizeNeeded
				);
				if (psd == NULL)
					__leave;

				psdNew = (PSECURITY_DESCRIPTOR)HeapAlloc(
					GetProcessHeap(),
					HEAP_ZERO_MEMORY,
					dwSdSizeNeeded
				);
				if (psdNew == NULL)
					__leave;

				dwSidSize = dwSdSizeNeeded;

				if (!GetUserObjectSecurity(
					hwinsta,
					&si,
					psd,
					dwSidSize,
					&dwSdSizeNeeded
				))
					__leave;
			}
			else
				__leave;

		if (!InitializeSecurityDescriptor(
			psdNew,
			SECURITY_DESCRIPTOR_REVISION
		))
			__leave;

		if (!GetSecurityDescriptorDacl(
			psd,
			&bDaclPresent,
			&pacl,
			&bDaclExist
		))
			__leave;

		ZeroMemory(&aclSizeInfo, sizeof(ACL_SIZE_INFORMATION));
		aclSizeInfo.AclBytesInUse = sizeof(ACL);
		if (pacl != NULL)
		{
			if (!GetAclInformation(
				pacl,
				(LPVOID)&aclSizeInfo,
				sizeof(ACL_SIZE_INFORMATION),
				AclSizeInformation
			))
				__leave;
		}

		dwNewAclSize = aclSizeInfo.AclBytesInUse + (2 *
			sizeof(ACCESS_ALLOWED_ACE)) + (2 * GetLengthSid(psid)) - (2 *
				sizeof(DWORD));
		pNewAcl = (PACL)HeapAlloc(
			GetProcessHeap(),
			HEAP_ZERO_MEMORY,
			dwNewAclSize
		);
		if (pNewAcl == NULL)
			__leave;

		if (!InitializeAcl(pNewAcl, dwNewAclSize, ACL_REVISION))
			__leave;

		if (bDaclPresent) 
		{
			
			if (aclSizeInfo.AceCount)
			{
				for (i = 0; i < aclSizeInfo.AceCount; i++)
				{
					// get an ACE
					if (!GetAce(pacl, i, &pTempAce))
						__leave;

					// add the ACE to the new ACL
					if (!AddAce(
						pNewAcl,
						ACL_REVISION,
						MAXDWORD,
						pTempAce,
						((PACE_HEADER)pTempAce)->AceSize
					))
						__leave;
				}
			}
		}

		// 
		// add the first ACE to the windowstation
		// 
		pace = (ACCESS_ALLOWED_ACE*)HeapAlloc(
			GetProcessHeap(),
			HEAP_ZERO_MEMORY,
			sizeof(ACCESS_ALLOWED_ACE) + GetLengthSid(psid) -
			sizeof(DWORD
				));
		if (pace == NULL)
			__leave;

		pace->Header.AceType = ACCESS_ALLOWED_ACE_TYPE;
		pace->Header.AceFlags = CONTAINER_INHERIT_ACE |
			INHERIT_ONLY_ACE |

			OBJECT_INHERIT_ACE;
		pace->Header.AceSize = sizeof(ACCESS_ALLOWED_ACE) +

			GetLengthSid(psid) - sizeof(DWORD);
		pace->Mask = GENERIC_ACCESS;

		if (!CopySid(GetLengthSid(psid), &pace->SidStart, psid))
			__leave;

		if (!AddAce(
			pNewAcl,
			ACL_REVISION,
			MAXDWORD,
			(LPVOID)pace,
			pace->Header.AceSize
		))
			__leave;

		// 
		// add the second ACE to the windowstation
		// 
		pace->Header.AceFlags = NO_PROPAGATE_INHERIT_ACE;
		pace->Mask = WINSTA_ALL;

		if (!AddAce(
			pNewAcl,
			ACL_REVISION,
			MAXDWORD,
			(LPVOID)pace,
			pace->Header.AceSize
		))
			__leave;

		// 
		// set new dacl for the security descriptor
		// 
		if (!SetSecurityDescriptorDacl(
			psdNew,
			TRUE,
			pNewAcl,
			FALSE
		))
			__leave;

		// 
// set the new security descriptor for the windowstation
// 
		if (!SetUserObjectSecurity(hwinsta, &si, psdNew))
			__leave;

		// 
		// indicate success
		// 
		bSuccess = TRUE;
	}
	__finally
	{
		// 
		// free the allocated buffers
		// 
		if (pace != NULL)
			HeapFree(GetProcessHeap(), 0, (LPVOID)pace);

		if (pNewAcl != NULL)
			HeapFree(GetProcessHeap(), 0, (LPVOID)pNewAcl);

		if (psd != NULL)
			HeapFree(GetProcessHeap(), 0, (LPVOID)psd);

		if (psdNew != NULL)
			HeapFree(GetProcessHeap(), 0, (LPVOID)psdNew);
	}

	return bSuccess;

}

BOOL AddTheAceDesktop(HDESK hdesk, PSID psid)
{

	ACL_SIZE_INFORMATION aclSizeInfo;
	BOOL                 bDaclExist;
	BOOL                 bDaclPresent;
	BOOL                 bSuccess = FALSE; // assume function will
											// fail
	DWORD                dwNewAclSize;
	DWORD                dwSidSize = 0;
	DWORD                dwSdSizeNeeded;
	PACL                 pacl;
	PACL                 pNewAcl=NULL;
	PSECURITY_DESCRIPTOR psd = NULL;
	PSECURITY_DESCRIPTOR psdNew = NULL;
	PVOID                pTempAce;
	SECURITY_INFORMATION si = DACL_SECURITY_INFORMATION;
	unsigned int         i;

	__try
	{
		// 
		// obtain the security descriptor for the desktop object
		// 
		if (!GetUserObjectSecurity(
			hdesk,
			&si,
			psd,
			dwSidSize,
			&dwSdSizeNeeded
		))
		{
			if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
			{
				psd = (PSECURITY_DESCRIPTOR)HeapAlloc(
					GetProcessHeap(),
					HEAP_ZERO_MEMORY,
					dwSdSizeNeeded
				);
				if (psd == NULL)
					__leave;

				psdNew = (PSECURITY_DESCRIPTOR)HeapAlloc(
					GetProcessHeap(),
					HEAP_ZERO_MEMORY,
					dwSdSizeNeeded
				);
				if (psdNew == NULL)
					__leave;

				dwSidSize = dwSdSizeNeeded;

				if (!GetUserObjectSecurity(
					hdesk,
					&si,
					psd,
					dwSidSize,
					&dwSdSizeNeeded
				))
					__leave;
			}
			else
				__leave;
		}

		// 
		// create a new security descriptor
		// 
		if (!InitializeSecurityDescriptor(
			psdNew,
			SECURITY_DESCRIPTOR_REVISION
		))
			__leave;

		// 
		// obtain the dacl from the security descriptor
		// 
		if (!GetSecurityDescriptorDacl(
			psd,
			&bDaclPresent,
			&pacl,
			&bDaclExist
		))
			__leave;

		// 
		// initialize
		// 
		ZeroMemory(&aclSizeInfo, sizeof(ACL_SIZE_INFORMATION));
		aclSizeInfo.AclBytesInUse = sizeof(ACL);

		// 
		// call only if NULL dacl
		// 
		if (pacl != NULL)
		{
			// 
			// determine the size of the ACL info
			// 
			if (!GetAclInformation(
				pacl,
				(LPVOID)&aclSizeInfo,
				sizeof(ACL_SIZE_INFORMATION),
				AclSizeInformation
			))
				__leave;
		}

		// 
		// compute the size of the new acl
		// 
		dwNewAclSize = aclSizeInfo.AclBytesInUse +
			sizeof(ACCESS_ALLOWED_ACE) +
			GetLengthSid(psid) - sizeof(DWORD);

		// 
		// allocate buffer for the new acl
		// 
		pNewAcl = (PACL)HeapAlloc(
			GetProcessHeap(),
			HEAP_ZERO_MEMORY,
			dwNewAclSize
		);
		if (pNewAcl == NULL)
			__leave;

		// 
		// initialize the new acl
		// 
		if (!InitializeAcl(pNewAcl, dwNewAclSize, ACL_REVISION))
			__leave;

		// 
		// if DACL is present, copy it to a new DACL
		// 
		if (bDaclPresent) // only copy if DACL was present
		{
			// copy the ACEs to our new ACL
			if (aclSizeInfo.AceCount)
			{
				for (i = 0; i < aclSizeInfo.AceCount; i++)
				{
					// get an ACE
					if (!GetAce(pacl, i, &pTempAce))
						__leave;

					// add the ACE to the new ACL
					if (!AddAce(
						pNewAcl,
						ACL_REVISION,
						MAXDWORD,
						pTempAce,
						((PACE_HEADER)pTempAce)->AceSize
					))
						__leave;
				}
			}
		}

		// 
		// add ace to the dacl
		// 
		if (!AddAccessAllowedAce(
			pNewAcl,
			ACL_REVISION,
			DESKTOP_ALL,
			psid
		))
			__leave;

		// 
		// set new dacl to the new security descriptor
		// 
		if (!SetSecurityDescriptorDacl(
			psdNew,
			TRUE,
			pNewAcl,
			FALSE
		))
			__leave;

		// 
		// set the new security descriptor for the desktop object
		// 
		if (!SetUserObjectSecurity(hdesk, &si, psdNew))
			__leave;

		// 
		// indicate success
		// 
		bSuccess = TRUE;
	}
	__finally
	{
		// 
		// free buffers
		// 
		if (pNewAcl != NULL)
			HeapFree(GetProcessHeap(), 0, (LPVOID)pNewAcl);

		if (psd != NULL)
			HeapFree(GetProcessHeap(), 0, (LPVOID)psd);

		if (psdNew != NULL)
			HeapFree(GetProcessHeap(), 0, (LPVOID)psdNew);
	}

	return bSuccess;
}

PSID BuildEveryoneSid() {
	SID_IDENTIFIER_AUTHORITY auth = SECURITY_WORLD_SID_AUTHORITY;
	PSID pSID = NULL;
	BOOL fSuccess = AllocateAndInitializeSid(&auth, 1,
		SECURITY_WORLD_RID, 0, 0, 0, 0, 0, 0, 0, &pSID);
	return(fSuccess ? pSID : NULL);
}
