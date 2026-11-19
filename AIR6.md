# AIR6 branch

Initial upstream commit: `4765b657625ec5bbda74b44400465fe043802b30`.

This branch imports SoftBank Air 6 / MT6990 board support from the owner's `softbank_air6_openwrt` source tree. The imported MediaTek platform and generic 6.18 kernel files preserve the previous Linux 6.18.51 build baseline, rather than combining those vendor patches with a newer kernel patch set. This also replaces shared MediaTek/generic files; other devices using them have not been retested.

Included here:

- MT6990 target, AIR6 device tree, kernel drivers/patches and boot/rootfs image recipes.
- Matching kernel-module and mac80211 recipes, hostapd integration, MT6990 HNAT and MT7990 Wi-Fi packages.
- Vendor build headers/configuration, `mkbootimg_v2.py` and `vendor-build-part.py`.
- `configs/air6.config`, a starting diffconfig from a recorded build. It is not a new successful build result.
- Default feeds pointing at the owner's five GitHub forks, all on `air6`.

The user-space AIR6 packages live in `royzheng/immortalwrt-packages:air6`; the LuCI modem application and Design theme live in `royzheng/immortalwrt-luci:air6`. The original `package/hcy`, `package/quectel` and `package/vendor` trees are not duplicated here. Generic `tools/` and `toolchain/` remain the ImmortalWrt versions.

## Build preparation on Linux

```sh
./scripts/feeds update -a
./scripts/feeds install -a
cp configs/air6.config .config
make defconfig
make download -j4
make -j2
```

Check `feeds.conf` if present: it takes precedence over `feeds.conf.default`. Save `feeds.buildinfo`, `config.buildinfo` and the main commit for each build because `;air6` tracks moving branch heads.

This migration has not performed a full firmware build or device boot test. AIR6 runtime files have now been split into MT6990 base-files, the Wi-Fi package and feed packages. Obsolete generic system copies are removed. The parent's personal init service is deliberately excluded from this repository; the parent build wrapper provides it through a Git-ignored files symlink. The old `build-vendor-public.py` helper is not used: it references missing `vendor-source`/`drivers` trees and Linux 6.18.44. Build the driver through its package recipe instead.

The Wi-Fi recipe still builds the driver dependency chain and installs the existing maintainer-provided `mt_wifi.ko.vendor` in place of the self-built `mt_wifi.ko`. Its SHA256 is `93b75de70dfd6e5c2446fc69cf4af47ba2bcc82c84d84cec88d1b9405c44c004`; this is a prebuilt component, not a claim that all installed modules were rebuilt from the imported source. Source copyright notices remain as supplied. See `vendor-include/README.md` for the header provenance clarification.

Ordinary boot images are unsigned. The prior device setup used a compatible signed boot. Building an image does not validate its signature or authorize flashing a device.

## Runtime ownership

MT6990 base-files owns network/MAC/LED defaults, recovery address and the existing signed-CPE upgrade hooks. The Wi-Fi package installs firmware, profiles, calibration extraction and startup loaders. Vendor modem services belong to the packages feed; language/theme defaults belong to the LuCI feed. Do not copy an old complete rootfs overlay over this tree. Upstream generates release metadata, package repositories, init links and module autoload files.

The MT6990 stage2 hook retains the existing authenticated update checks and service-pause behavior; neither flashing nor boot has been tested by this migration. The personal parent overlay is not a dependency of compiling the standalone fork.
