#include <nss.h>
#include <shadow.h>
#include <stdio.h>
#include "nss_debug-log.h"

/*************************************
 * Functions for the shadow database. *
 *************************************/


// Called to open the shadow file
enum nss_status
_nss_debug_setspent(int stayopen)
{
    nss_debug_log("NSS DEBUG: Called %s with args (stayopen: %d)", __FUNCTION__, stayopen);
    // Must be marked as success otherwise getpwent_r won't be called.
    return NSS_STATUS_SUCCESS;
}


// Called to close the shadow file
enum nss_status
_nss_debug_endspent(void)
{
    nss_debug_log("NSS DEBUG: Called %s", __FUNCTION__);
    return NSS_STATUS_NOTFOUND;
}


// Called to look up next entry in the shadow file
enum nss_status
_nss_debug_getspent_r(struct spwd *result, char *buffer, size_t buflen, int *errnop)
{
    nss_debug_log("NSS DEBUG: Called %s", __FUNCTION__);
    return NSS_STATUS_NOTFOUND;
}


// Find a shadow entry by name
enum nss_status
_nss_debug_getspnam_r(const char *name, struct spwd *result, char *buffer, size_t buflen, int *errnop)
{
    nss_debug_log("NSS DEBUG: Called %s with args (name: %s)", __FUNCTION__, name);
    return NSS_STATUS_NOTFOUND;
}
