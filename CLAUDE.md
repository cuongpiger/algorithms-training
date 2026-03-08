# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repository Purpose

A personal competitive programming solutions archive. Each solution file is numbered sequentially and stored flat in `solutions/`. The README.md serves as an index table.

## README.md Table Maintenance

The table columns are:

| Column | Format |
|--------|--------|
| No | Descending ordinal (new entries go at the top) |
| Problem Title | `[Title](URL)` — always request the URL from the user if not provided |
| Organization | Online judge name (e.g. `LeetCode`, `Codeforces`, `UVA`) |
| Solution | `[<No>.<ext>](./solutions/<No>.<ext>)` |
| Algorithm | Comma-separated backtick tags, e.g. `` `dfs`, `tree` `` |
| Time Complexity | LaTeX in `$$...$$`, e.g. `$$O(n \log n)$$` |

Table row template:
```
|<No>|[Title](URL)|Organization|[<No>.<ext>](./solutions/<No>.<ext>)|`tag1`, `tag2`|$$O(...)$$|
```

Starred/notable entries use `⭐` or `💜` suffixes on the No column (user's choice, not required).

## Workflow

### Adding a new solution to README.md
1. Ask the user for the problem URL if not already provided.
2. Determine the next No (current highest + 1).
3. Identify the solution file extension to fill the Solution column.
4. Calculate time complexity from the solution code.
5. Insert a new row at the **top** of the table (below the header).

### Committing and pushing
When the user asks to commit and push with no other requests: stage all changed files, commit, and push to origin. No README update needed unless explicitly requested.

## Solution File Naming

Files follow `<sequential_number>.<extension>` with no subdirectories. Languages used include `.py`, `.cpp`, `.go`, `.java`, `.js`, `.ts`.
