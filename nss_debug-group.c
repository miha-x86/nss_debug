#include <grp.h>
#include <nss.h>
#include <stdio.h>
#include "nss_debug-log.h"

/*************************************
 * Functions for the group database. *
 *************************************/


// Called to open the group file
enum nss_status
_nss_debug_setgrent(int stayopen)
{
    nss_debug_log("NSS DEBUG: Called %s with args (stayopen: %d)", __FUNCTION__, stayopen);
    // Must be marked as success otherwise getpwent_r won't be called.
    return NSS_STATUS_SUCCESS;
}


// Called to close the group file
enum nss_status
_nss_debug_endgrent(void)
{
    nss_debug_log("NSS DEBUG: Called %s", __FUNCTION__);
    return NSS_STATUS_NOTFOUND;
}


// Called to look up next entry in group file
enum nss_status
_nss_debug_getgrent_r(struct group *result, char *buffer, size_t buflen, int *errnop)
{
    nss_debug_log("NSS DEBUG: Called %s", __FUNCTION__);
    return NSS_STATUS_NOTFOUND;
}


// Find a group by gid
enum nss_status
_nss_debug_getgrgid_r(gid_t gid, struct group *result, char *buffer, size_t buflen, int *errnop)
{
    nss_debug_log("NSS DEBUG: Called %s with args (gid: %d)", __FUNCTION__, gid);
    return NSS_STATUS_NOTFOUND;
}


// Find a group by name
enum nss_status
_nss_debug_getgrnam_r(const char *name, struct group *result, char *buffer, size_t buflen, int *errnop)
{
    nss_debug_log("NSS DEBUG: Called %s with args (name: %s)", __FUNCTION__, name);
    return NSS_STATUS_NOTFOUND;
}
