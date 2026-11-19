# AIR6 vendor build headers

These headers are used by the AIR6 wireless build; this directory is not a firmware image or an installed runtime library.

| File | Consumer | Purpose |
| --- | --- | --- |
| `mtk_nl80211_inc/mtk_vendor_nl80211.h` | MT7990 driver, through `scripts/vendor-build-part.py` | MediaTek vendor nl80211 command and attribute definitions used by the driver |
| `mtk_nl80211_inc_618/mtk_vendor_nl80211.h` | `package/network/services/hostapd/Makefile` | Vendor nl80211 definitions matching the hostapd integration |
| `vendor618_compat.h` | Force-included by `scripts/vendor-build-part.py` | Kernel headers and `mtk_strlcpy`, preserving the legacy API's return value |
| `vendor618_wext.h` | Force-included for the Wi-Fi driver build | WEXT stream serialization compatibility helpers for Linux 6.18 |

The two nl80211 headers are different interfaces and are not interchangeable merely because they have the same filename.

The owner identified the former `mtk_nl80211_inc_618/LICENSES/` directory as arbitrarily copied material. It is not imported as evidence of licensing. Original copyright and SPDX statements in the source files remain intact; this migration adds no blanket license grant to files without one. Standard license texts already supplied by the build tree are under `LICENSES/`.
