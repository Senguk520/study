---
name: acm-stl-md-template
overview: 为 `STL.md` 准备一份面向算法竞赛新手的 C++17 STL 入门示例文档，覆盖 `vector`、`map`/`unordered_map`、`set` 的常用操作，并以中文详细注释说明复杂度与竞赛坑点。
todos:
  - id: rewrite-stl-outline
    content: 重写 STL.md 的章节结构与说明框架
    status: completed
  - id: add-vector-examples
    content: 补充 vector 初始化插入排序去重示例
    status: completed
    dependencies:
      - rewrite-stl-outline
  - id: add-map-wordcount
    content: 补充 map 对比与单词统计示例
    status: completed
    dependencies:
      - rewrite-stl-outline
  - id: add-set-and-pitfalls
    content: 补充 set 操作与竞赛坑点总结
    status: completed
    dependencies:
      - add-vector-examples
      - add-map-wordcount
  - id: review-comments-complexity
    content: 统一校对注释风格与复杂度标注
    status: completed
    dependencies:
      - add-set-and-pitfalls
---

## User Requirements

- 在 `c:/Users/asus/Desktop/study/STL.md` 中整理一份算法竞赛用的 STL 入门笔记与示例。
- 内容需覆盖：顺序容器的常见操作、关联容器的查找/计数场景、集合的插入与查询、容器选型差异。
- 代码讲解要面向只有基础语法知识的新手，注释详细、直观，便于赛场快速照抄和理解。
- 每个操作都要标明复杂度，并提醒竞赛中的常见坑点，如排序后再去重、哈希退化、状态清空等。

## Product Overview

- 产出一份单文件竞赛笔记，主体为可直接复用的示例代码块配合中文说明。
- 视觉效果以清晰易读为主：按主题分段，先说明用途，再给示例，最后补充复杂度和易错点。

## Core Features

- 展示顺序容器的初始化、尾部插入、升降序排序、去重流程。
- 说明两种键值容器的核心区别与适用场景。
- 给出一段文本的单词出现次数统计示例，并展示遍历输出。
- 展示集合的插入、判重、查找写法。
- 强制包含结构化绑定与范围 `for` 的示例。

## Tech Stack Selection

- 文档载体：Markdown
- 示例语言：C++17
- 组织方式：分节说明 + 代码块 + 复杂度/坑点注释

## Implementation Approach

- 采用“概念说明 -> 最小可用示例 -> 复杂度 -> 竞赛坑点” 的固定结构，在单个 Markdown 文件中完成整理，避免分散知识点。
- 代码全部使用竞赛常见短写法，但保留足够详细的中文注释，确保新手能看懂且能在赛场快速复现。
- 关键技术决策：
- `vector` 去重使用“排序 + unique + erase”标准竞赛写法，避免误以为 `unique` 会直接删除元素。
- 单词统计同时展示有序映射与无序映射的定位差异，并明确 `unordered_map` 为平均复杂度、极端情况下可能退化。
- 遍历输出强制加入范围 `for`，键值遍历强制加入结构化绑定，满足学习目标并贴近竞赛习惯。
- 性能与可靠性：
- `push_back` 为均摊 `O(1)`；排序为 `O(n log n)`；`set/map` 基本操作为 `O(log n)`；`unordered_map` 插入/查询平均 `O(1)`、最坏 `O(n)`。
- 文本统计示例应避免过度复杂的字符串清洗逻辑，优先给出竞赛可快速理解版本，并注明大小写/标点处理是否简化。

## Implementation Notes

- 保留并替换当前 `STL.md` 中的占位内容，不扩散到其他文件。
- 注释重点放在“为什么这么写”和“复杂度是多少”，避免长篇理论导致笔记失去赛场参考价值。
- 明确写出 `unique` 前通常先排序；多组数据场景下，容器需要重新构造或 `clear()`。
- `unordered_map` 说明中补充“不保证有序”，避免用户把其输出顺序当作特性依赖。

## Architecture Design

- 当前工作区是轻量笔记型结构，本次改动保持为单文件知识文档，不引入额外模块。
- 文档内部建议按以下关系组织：

1. `vector` 基础操作
2. `map` 与 `unordered_map` 对比
3. 单词统计完整例子
4. `set` 插入与查找
5. 竞赛坑点总结

## Directory Structure

## Directory Structure Summary

本次实现仅修改一个现有 Markdown 文件，在其中补充完整的算法竞赛 STL 示例与说明。

```text
c:/Users/asus/Desktop/study/
└── STL.md  # [MODIFY] STL 竞赛笔记主文件。补充 vector/map/unordered_map/set 示例、复杂度说明、结构化绑定与范围 for 用法，以及竞赛常见坑点提示。
```