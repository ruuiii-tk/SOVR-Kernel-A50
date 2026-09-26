# 🚀 SOVR Kernel for Samsung Galaxy A50

[![Linux Kernel](https://img.shields.io/badge/Linux-4.14.210_LTS-blue.svg?logo=linux)](https://kernel.org)
[![Target SoC](https://img.shields.io/badge/SoC-Exynos_9610-orange.svg)](https://semiconductor.samsung.com)
[![Compiler](https://img.shields.io/badge/Compiler-Proton_Clang_13_LTO-success.svg)](https://llvm.org)
[![MGLRU](https://img.shields.io/badge/Feature-Multi--Gen_LRU-green.svg)](https://docs.kernel.org/admin-guide/mm/multigen_lru.html)
[![ZRAM](https://img.shields.io/badge/ZRAM-ZSTD_3.87%3A1-purple.svg)]()
[![TCP](https://img.shields.io/badge/TCP-Google_BBR-red.svg)]()

**SOVR Kernel** is a custom, high-performance, security-hardened Linux kernel engineered specifically for the **Samsung Galaxy A50** (`SM-A505F`, Exynos 9610) running **Android 12 (One UI 4.1 / AOSP GSIs)**.

Developed through a rigorous, zero-blind-breakage incremental roadmap, SOVR modernizes the legacy Samsung 4.14 baseline with state-of-the-art memory management, next-generation network congestion algorithms, optimized storage scheduling, and an ongoing upstream LTS rebase towards **OpenELA Enterprise Linux**.

---

## ✨ Key Features & Architectural Innovations

### 🧠 Multi-Gen LRU (MGLRU)
* Full 12-patch series backported from upstream Linux / Google Android common kernel.
* Replaces the legacy 2-list LRU algorithm with multi-generational generation-based page reclamation.
* Active core aging (`/sys/kernel/mm/lru_gen/enabled = 0x0001`), dramatically reducing low-memory thrashing and app redraws.

### ⚡ Ultra-Efficient ZRAM with ZSTD Compression
* Default swap compression engine set to **Zstandard (ZSTD)**.
* Verified live compression ratio of **~3.87:1** (e.g., 571 MB of resident data compressed into just 147 MB of physical RAM).
* Extends usable RAM for multitasking without CPU overhead.

### 🌐 Google BBR Congestion Control
* Default TCP congestion algorithm configured to **BBR (Bottleneck Bandwidth and RTT)**.
* Significantly improves Wi-Fi and LTE network throughput, latency under bufferbloat, and connection stability.

### 💾 Anxiety I/O Storage Scheduler
* Default I/O elevator tuned specifically for UFS 2.1 flash storage.
* Minimizes write latencies and background flush spikes during app installations and SQLite database transactions.

### 🛡️ Security Hardening
* Enabled `CONFIG_FORTIFY_SOURCE=y` buffer overflow protection across string and memory functions.
* Clean separation and compatibility preservation for Samsung low-level TrustZone, RKP, and SYSMMU interfaces.

### 🏗️ Cutting-Edge Toolchain & Link-Time Optimization
* Compiled with **Proton Clang 13.0.0** (LLVM).
* Full kernel **Link-Time Optimization (LTO)** enabled (`vmlinux.o`), optimizing inter-procedural code paths and dead-code stripping.

---

## 📈 Long-Term Support (LTS) Rebase Roadmap

| Milestone | Subversion | Status | Highlights |
| :--- | :--- | :--- | :--- |
| **SOVR v1.0 - v1.3** | `4.14.194` | ✅ Tested Live | Clean base, BBR, ZSTD ZRAM, MGLRU backport, Anxiety I/O |
| **SOVR v2.0** | `4.14.195` | ✅ Tested Live | First upstream LTS bump; Android RCU eventpoll fix |
| **SOVR v2.1** | `4.14.196` | ✅ Tested Live | Samsung composite USB NCM restoration; UART adaptation |
| **SOVR v2.2** | `4.14.200` | ✅ Tested Live | Cumulative 4-release leap (197-200); 374 files updated |
| **SOVR v2.3** | `4.14.210` | ✅ Tested Live | Cumulative 10-release mega leap (201-210); 626 files updated |
| **SOVR v2.4 (Next)** | `4.14.220` | 🔄 In Progress | Frontier LTS leap (211-220) |
| **SOVR Final** | `4.14.336+` | 🎯 Planned | OpenELA Enterprise Linux post-EOL maintenance sync |

---

## 📱 Supported Devices & Compatibility

* **Primary Device:** Samsung Galaxy A50 (`SM-A505F` / `a50`)
* **Platform:** Samsung Exynos 9610 (4x Cortex-A73 + 4x Cortex-A53, Mali-G72 MP3)
* **Supported ROMs:**
  * Samsung One UI 4.1 (Android 12 Ports / FreshROMs)
  * Generic System Images (AOSP / LineageOS Android 12 GSIs)

---

## 📦 Installation Instructions

> [!IMPORTANT]
> The device must have an unlocked bootloader and a custom recovery (such as **TWRP**) installed.

1. Download the latest flashable ZIP (`SOVR-Kernel-v*.zip`) from [GitHub Releases](https://github.com/ruuiii-tk/SOVR-Kernel-A50/releases).
2. Copy the ZIP file to your device's internal storage or MicroSD card.
3. Reboot into **TWRP Recovery**.
4. Select **Install**, choose the SOVR Kernel ZIP, and swipe to flash.
5. Wipe Dalvik/ART Cache (optional, recommended).
6. Reboot to **System**.

---

## 🛠️ Building from Source

Builds are performed on **Ubuntu 22.04 LTS (WSL2 / Native)** with `ccache` acceleration:

```bash
# Clone the repository
git clone -b sovr-beta https://github.com/ruuiii-tk/SOVR-Kernel-A50.git
cd SOVR-Kernel-A50

# Compile for Galaxy A50 (One UI 4 / Android 12)
./build.sh -d a50 -a 12 -v oneui -n
```

Packaged AnyKernel3 zip files are automatically created in the workspace.

---

## 🤝 Origin & Acknowledgements

**SOVR Kernel** was originally based on the foundation provided by the **Mint Kernel** project developed by [@TenSeventy7](https://github.com/TenSeventy7) and the [FreshROMs](https://github.com/FreshROMs) team for the Exynos 9610 platform. We are deeply grateful for their groundwork and community contributions.

We also acknowledge and credit upstream contributors whose architectural work enabled SOVR:
* **Linux Kernel Stable Team** ([Greg Kroah-Hartman](https://github.com/gregkh))
* **Google Android Common Kernel Team** (Multi-Gen LRU & BBR maintainers)
* **OpenELA** (Enterprise Linux Association) for post-336 LTS preservation
* **Cruel Kernel & ShadowX** teams for Exynos scheduler and memory insights
* **osm0sis** for the indispensable AnyKernel3 installer

---

## 📄 License
SOVR Kernel is licensed under the **GNU General Public License v2.0 (GPLv2)**. See the [LICENSE](LICENSE) file for complete details.
