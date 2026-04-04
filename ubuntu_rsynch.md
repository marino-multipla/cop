# RSYNC – Fast and Efficient File Copy & Sync

`rsync` is a powerful command-line utility to **copy, synchronize, and backup files/folders** efficiently, both locally and over a network. It is widely used for large datasets, backups, and repeated file transfers.

---

## 🌟 Main Benefits

1. **Fast and Incremental**
   - Only copies **new or changed files**.
   - Skips files that are already up-to-date.

2. **Progress Monitoring**
   - Shows per-file progress.
   - Can display **overall progress and ETA** for large transfers.

3. **Resumable Transfers**
   - If a transfer is interrupted, rerunning the command resumes from where it left off.

4. **Preserves File Metadata**
   - Keeps timestamps, permissions, symbolic links, and directory structure.

5. **Versatile**
   - Works **locally** or over **network** (via SSH).
   - Ideal for backups, mirroring, or large data migrations.

---

## ⚙️ Common Flags

| Flag | Description |
|------|-------------|
| `-a`  | Archive mode: preserves permissions, timestamps, symbolic links, and folder structure |
| `-v`  | Verbose: shows files being transferred |
| `--progress` | Displays per-file progress during transfer |
| `--info=progress2` | Shows a **single overall progress bar** with total percentage, speed, and ETA |
| `-z`  | Compresses files during transfer (useful for network transfers) |
| `--delete` | Deletes files in the destination that are missing in the source (mirror mode) |
| `-h`  | Human-readable numbers for sizes and speeds |

---

## 💻 Basic Usage Examples

### 1. Copy a folder locally

```bash
rsync -av --info=progress2 /path/to/source/ /path/to/destination/
