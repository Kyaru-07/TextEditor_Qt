# 图标说明（Tabler Icons）

来源：https://tabler.io/icons ｜ 许可：MIT ｜ 共 32 个 SVG，24×24 线性描边，`stroke="currentColor"`。

引用方式（已在 `icons.qrc` 中登记，前缀 `/icons`）：

```cpp
btnSave->setIcon(QIcon(QStringLiteral(":/icons/file-save.svg")));
```

| qrc 资源路径 | Tabler 图标名 | 用途 | 备注 |
|---|---|---|---|
| `:/icons/file-new.svg` | `file-plus` | 新建 |  |
| `:/icons/file-open.svg` | `folder-open` | 打开 |  |
| `:/icons/file-save.svg` | `device-floppy` | 保存 |  |
| `:/icons/file-save-as.svg` | `copy-plus` | 另存为 | Tabler 没有原生 save-as，用 copy-plus（复制+新建）替代 |
| `:/icons/file-print.svg` | `printer` | 打印 |  |
| `:/icons/file-print-preview.svg` | `eye` | 打印预览 | 用 eye 表示预览 |
| `:/icons/file-exit.svg` | `x` | 退出 |  |
| `:/icons/edit-undo.svg` | `arrow-back-up` | 撤销 |  |
| `:/icons/edit-redo.svg` | `arrow-forward-up` | 重做 |  |
| `:/icons/edit-cut.svg` | `cut` | 剪切 |  |
| `:/icons/edit-copy.svg` | `copy` | 复制 |  |
| `:/icons/edit-paste.svg` | `clipboard` | 粘贴 |  |
| `:/icons/edit-delete.svg` | `trash` | 删除 |  |
| `:/icons/edit-select-all.svg` | `select-all` | 全选 | 虚线选框，表示框选全部 |
| `:/icons/edit-find.svg` | `search` | 查找 |  |
| `:/icons/edit-find-next.svg` | `arrow-down` | 查找下一个 | 用 arrow-down 表示"下一个" |
| `:/icons/edit-replace.svg` | `replace` | 替换 |  |
| `:/icons/format-font.svg` | `abc` | 字体 |  |
| `:/icons/format-font-size.svg` | `text-size` | 字号 |  |
| `:/icons/format-font-color.svg` | `text-color` | 字体颜色 |  |
| `:/icons/format-bg-color.svg` | `paint` | 背景颜色 |  |
| `:/icons/format-bold.svg` | `bold` | 粗体 |  |
| `:/icons/format-italic.svg` | `italic` | 斜体 |  |
| `:/icons/format-underline.svg` | `underline` | 下划线 |  |
| `:/icons/format-wrap.svg` | `text-wrap` | 自动换行 |  |
| `:/icons/view-linenumber.svg` | `list-numbers` | 显示行号 |  |
| `:/icons/view-toolbar.svg` | `layout-navbar` | 工具栏显隐 |  |
| `:/icons/view-statusbar.svg` | `layout-bottombar` | 状态栏显隐 |  |
| `:/icons/help-about.svg` | `info-circle` | 关于 |  |
| `:/icons/help-help.svg` | `help` | 帮助 |  |
| `:/icons/autosave.svg` | `history` | 定时自动保存 |  |
| `:/icons/warn-unsaved.svg` | `alert-triangle` | 未保存警告 |  |

> 图标颜色跟随控件调色板（`currentColor`）。想单独染色可在 SVG 里把 `currentColor` 改成具体色值，或用 QPainter 着色后再 `setIcon`。