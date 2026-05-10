---
name: export-cpp17-template-md
overview: 将上一轮生成的 C++17 万能基础竞赛模板及关于 `\n` 与 `endl` 的说明导出为当前工作区中的 Markdown 文件。
todos:
  - id: write-template-md
    content: 写入 study,md，导出 C++17 基础竞赛模板文档
    status: completed
  - id: add-io-explanation
    content: 补充 \n 替代 endl 的中文解释
    status: completed
    dependencies:
      - write-template-md
  - id: verify-md-content
    content: 检查 Markdown 结构、代码块和关键要求完整性
    status: completed
    dependencies:
      - add-io-explanation
---

## 用户需求

将前面生成的 C++17 “万能基础竞赛模板”导出为一份 Markdown 文件。

## 产品概览

在当前工作区生成或写入一份 `.md` 文档，用于保存算法竞赛基础模板，方便用户赛前复习、复制和直接使用。

## 核心功能

- Markdown 文档包含清晰标题与分节结构。
- 包含 C++17 基础竞赛模板代码块。
- 模板必须包含 `#include &lt;bits/stdc++.h&gt;`。
- 模板必须包含快速 I/O：`ios::sync_with_stdio(false); cin.tie(0);`。
- 模板必须包含支持 T 组独立测试数据的 `solve()` 函数结构。
- 文档需要用中文解释为什么竞赛中推荐使用 `\n` 替代 `endl`。
- 文档需要提醒常见竞赛坑点，包括整型溢出、多组数据状态清空、输入输出超时等。

## 技术栈选择

- 文档格式：Markdown
- 代码标准：C++17
- 目标文件：`c:/Users/asus/Desktop/study/study,md`
- 当前项目状态：工作区仅包含空的 `study,md` 文件，可作为本次导出目标文件。

## 实现方案

将竞赛模板整理为结构化 Markdown 文档，写入当前已打开的 `study,md` 文件。文档采用“标题 + 使用说明 + C++ 代码块 + 重点解释 + 常见坑点”的形式，确保既能直接复制代码，也能作为学习笔记阅读。

关键决策：

- 复用当前空文件 `study,md`，避免额外创建不必要文件。
- 使用 fenced code block 标记 C++ 代码，保证 Markdown 预览和复制体验清晰。
- 模板代码保持精简，不引入复杂封装，符合 ACM/CCPC 快速书写需求。
- 注释采用中文详细解释，重点覆盖快速 I/O、多测结构、复杂度与常见错误。

## 实施注意事项

- 写入前确认目标文件为空，避免覆盖用户已有内容；当前已确认 `study,md` 为空。
- 代码中使用 `'\n'` 展示推荐换行方式，避免 `endl` 带来的频繁刷新开销。
- 说明多组测试时 `solve()` 内局部变量天然自动清空，全局数组、容器、标记数组需要手动重置。
- 保持文档内容集中，不扩展到高级算法模板，避免超出“万能基础竞赛模板”范围。

## 架构设计

本任务为单文档导出，不需要引入项目架构或模块拆分。文档内部结构如下：

1. 文档标题
2. 模板适用场景
3. C++17 基础模板代码
4. `\n` 与 `endl` 的区别说明
5. 竞赛常见坑点提醒

## 目录结构

```text
c:/Users/asus/Desktop/study/
└── study,md  # [MODIFY] Markdown 导出文件。写入 C++17 万能基础竞赛模板、中文注释、快速 I/O 说明、多测 solve() 结构和常见坑点提醒。
```