/*
 * Public-tree stub for the trimmed sec_profile.c.
 *
 * The original sec_profile.c was excluded from the public source release
 * while every other file kept referencing it.  These three entry points are
 * optional profile parsers called from cmm_profile.c while reading the
 * vendor .dat file: extra security tokens plus the 802.11r FT and OCE
 * parameter blocks.  Doing nothing here leaves every affected setting at
 * its built-in default, which keeps the module linkable without inventing
 * parser behaviour that cannot be verified against the original.
 */
#include "rt_config.h"

VOID ReadSecurityParameterFromFile(
	IN PRTMP_ADAPTER pAd,
	IN RTMP_STRING *tmpbuf,
	IN RTMP_STRING *pBuffer)
{
}

#ifdef CONFIG_AP_SUPPORT
#ifdef DOT11R_FT_SUPPORT
void FT_rtmp_read_parameters_from_file(
	IN PRTMP_ADAPTER pAd,
	RTMP_STRING *tmpbuf,
	RTMP_STRING *pBuffer)
{
}
#endif /* DOT11R_FT_SUPPORT */

#ifdef OCE_SUPPORT
void Oce_read_parameters_from_file(
	IN PRTMP_ADAPTER pAd,
	RTMP_STRING *tmpbuf,
	RTMP_STRING *pBuffer)
{
}
#endif /* OCE_SUPPORT */
#endif /* CONFIG_AP_SUPPORT */
