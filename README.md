# 🚀 SOVR Kernel for Samsung Galaxy A50

[![Linux Kernel](https://img.shields.io/badge/Linux-4.14.357--openela-blue.svg?logo=linux)](https://github.com/openela/kernel-lts)
[![Release](https://img.shields.io/badge/Release-SOVR_v3.3-success.svg?logo=github)](https://github.com/ruuiii-tk/SOVR-Kernel-A50/releases/tag/v3.3)
[![Target SoC](https://img.shields.io/badge/SoC-Exynos_9610-orange.svg)](https://semiconductor.samsung.com)
[![Compiler](https://img.shields.io/badge/Compiler-Proton_Clang_13_LTO-success.svg)](https://llvm.org)
[![Root](https://img.shields.io/badge/Root-KernelSU--Next-red.svg)](https://github.com/KernelSU-Next/KernelSU-Next)
[![MGLRU](https://img.shields.io/badge/Feature-Multi--Gen_LRU-green.svg)](https://docs.kernel.org/admin-guide/mm/multigen_lru.html)
[![ZRAM](https://img.shields.io/badge/ZRAM-ZSTD_3.87%3A1-purple.svg)]()
[![TCP](https://img.shields.io/badge/TCP-Google_BBR-red.svg)]()

**SOVR Kernel** is a state-of-the-art, high-performance, security-hardened Linux kernel engineered specifically for the **Samsung Galaxy A50** (\SM-A505F/FN/G/N\, Exynos 9610) running **Android 12 (One UI 4.1 / AOSP GSIs)**.

Developed through a rigorous, zero-blind-breakage incremental roadmap, SOVR modernizes the legacy Samsung 4.14 baseline to the latest **OpenELA Enterprise Linux (4.14.357)**, featuring **KernelSU-Next** integration with Knox EL3 RKP bypass, next-generation memory management, optimized storage scheduling, and low-latency networking.

---

## ✨ Key Features & Architectural Innovations

### 🛡️ Modern KernelSU-Next Integration
* In-tree **KernelSU-Next** driver integrated with manual inline hooks (\CONFIG_KSU_MANUAL_HOOK=y\).
* Specifically engineered to bypass Samsung Knox EL3 Real-time Kernel Protection (RKP) write protections.
* Full root management and module execution while preserving **SELinux Enforcing** mode for banking and enterprise apps.

### ⚡ Dynamic Fsync 2.0
* Automatically suspends filesystem sync operations while the screen is on and interactive, cutting storage I/O bottlenecks.
* Flushes pending writes immediately when the screen turns off or goes idle, preventing data loss while maximizing UI smoothness.

### 🧠 Multi-Gen LRU (MGLRU)
* Full 12-patch series backported from upstream Linux and Google Android Common Kernel.
* Replaces the legacy 2-list LRU algorithm with multi-generational generation-based page reclamation.
* Active core aging (\/sys/kernel/mm/lru_gen/enabled = 0x0001\), dramatically reducing low-memory thrashing and app redraws.

### ⚡ Ultra-Efficient ZRAM with ZSTD Compression
* Default swap compression engine set to **Zstandard (ZSTD)**.
* Verified live compression ratio of **~3.87:1** (e.g., 571 MB of resident data compressed into just 147 MB of physical RAM).
* Extends usable RAM for multitasking without CPU overhead.

### 🌐 Google BBR Congestion Control
* Default TCP congestion algorithm configured to **BBR (Bottleneck Bandwidth and RTT)**.
* Significantly improves Wi-Fi and LTE network throughput, latency under bufferbloat, and connection stability.

### 💾 Anxiety I/O Storage Scheduler
* Default I/O elevator tuned specifically for flash storage (UFS / eMMC 5.1).
* Minimizes write latencies and background flush spikes during app installations and SQLite database transactions.

### 📂 In-Kernel OverlayFS
* Built-in support for modular systemless root and module overlays without userspace FUSE overhead.

### 🏗️ Cutting-Edge Toolchain & Link-Time Optimization
* Compiled with **Proton Clang 13.0.0** (LLVM).
* Full kernel **Link-Time Optimization (LTO)** enabled (\mlinux.o\), optimizing inter-procedural code paths and dead-code stripping.

---

## 📈 Long-Term Support (LTS) & Feature Roadmap

| Milestone | Base Linux | Status | Highlights |
| :--- | :--- | :--- | :--- |
| **SOVR v1.0 - v1.3** | .14.194\ | ✅ Complete | Clean base, BBR, ZSTD ZRAM, MGLRU backport, Anxiety I/O |
| **SOVR v2.0 - v2.3** | .14.195 - 210\ | ✅ Complete | USB NCM adaptation, Android RCU fixes, 626 upstream files updated |
| **SOVR v2.4 - v2.9** | .14.211 - 280\ | ✅ Complete | Progressive LTS leaps across memory management and arm64 core |
| **SOVR v3.0** | .14.336\ | ✅ Complete | Final official Linux 4.14 upstream LTS release reached |
| **SOVR v3.1** | .14.357-openela\ | ✅ Complete | OpenELA Enterprise Linux post-EOL maintenance sync |
| **SOVR v3.2** | .14.357-openela\ | ✅ Complete | KernelSU v0.9.5, Dynamic Fsync 2.0, OverlayFS, Quad release pipeline |
| **SOVR v3.3** | .14.357-openela\ | ✅ Current Stable | KernelSU-Next in-tree manual hooks, Knox EL3 RKP bypass, Production release |
| **SOVR v3.4** | .14.357-openela\ | 🎯 Next Frontier | BBR FQ packet pacing, WireGuard in-kernel, LZ4 ZRAM multitasking acceleration, Knox privacy/telemetry cleanup, Schedutil EAS latency tuning |

---

## 📱 Supported Devices & Compatibility

* **Primary Device:** Samsung Galaxy A50 (\SM-A505F\ / \SM-A505FN\ / \SM-A505G\ / \SM-A505N\)
* **Platform:** Samsung Exynos 9610 (4x Cortex-A73 @ 2.3GHz + 4x Cortex-A53 @ 1.7GHz, Mali-G72 MP3)
* **Supported ROMs:**
  * Samsung One UI 4.1 (Android 12 Ports / FreshROMs)
  * Generic System Images (AOSP / LineageOS / PixelExperience Android 12 GSIs)

---

## 📦 Downloads & Variants

Latest releases are available under [GitHub Releases](https://github.com/ruuiii-tk/SOVR-Kernel-A50/releases):

* **OneUI 4 (KSU):** \SOVR-Kernel-v*.A12_OneUI4_A50_KSU.zip\ (Pre-rooted with KernelSU-Next)
* **OneUI 4 (Standard):** \SOVR-Kernel-v*.A12_OneUI4_A50.zip\ (Stock rootless / Magisk compatible)
* **AOSP (KSU):** \SOVR-Kernel-v*.A12_AOSP_A50_KSU.zip\ (For GSIs / LineageOS with KernelSU-Next)
* **AOSP (Standard):** \SOVR-Kernel-v*.A12_AOSP_A50.zip\ (For GSIs / LineageOS rootless)

---

## 📲 Installation Instructions

> [!IMPORTANT]
> The device must have an unlocked bootloader and a custom recovery (such as **TWRP** or **OrangeFox**) installed.

1. Download the flashable ZIP corresponding to your ROM from [GitHub Releases](https://github.com/ruuiii-tk/SOVR-Kernel-A50/releases).
2. Copy the ZIP file to your device internal storage or MicroSD card.
3. Reboot into **TWRP Recovery**.
4. Select **Install**, choose the SOVR Kernel ZIP, and swipe to flash.
5. (Optional, recommended) Wipe Dalvik / ART Cache.
6. Reboot to **System**.
7. If using a KSU build, install the **KernelSU-Next Manager APK** to grant superuser access.

---

## 🛠️ Building from Source

Builds are performed on **Ubuntu 22.04 LTS (WSL2 / Native)** with Proton Clang 13 and \ccache\:

\\ash
# Clone the repository
git clone -b sovr-beta https://github.com/ruuiii-tk/SOVR-Kernel-A50.git
cd SOVR-Kernel-A50

# Compile for Galaxy A50 (One UI 4 / Android 12 with KernelSU-Next)
./build.sh -d a50 -a 12 -v oneui -n
\
---

## 🤝 Origin & Acknowledgements

**SOVR Kernel** was originally based on the foundation provided by the **Mint Kernel** project developed by [@TenSeventy7](https://github.com/TenSeventy7) and the [FreshROMs](https://github.com/FreshROMs) team for the Exynos 9610 platform. We are deeply grateful for their groundwork and community contributions.

We also acknowledge and credit upstream contributors whose architectural work enabled SOVR:
* **Linux Kernel Stable Team** ([Greg Kroah-Hartman](https://github.com/gregkh))
* **Google Android Common Kernel Team** (Multi-Gen LRU & BBR maintainers)
* **OpenELA** (Enterprise Linux Association) for post-336 LTS preservation
* **KernelSU & KernelSU-Next Teams** (tiann, rifsxd) for next-generation root architecture
* **Cruel Kernel & ShadowX** teams for Exynos scheduler and memory insights
* **osm0sis** for the indispensable AnyKernel3 installer

---

## 📄 License
SOVR Kernel is licensed under the **GNU General Public License v2.0 (GPLv2)**. See the [LICENSE](LICENSE) file for complete details.
