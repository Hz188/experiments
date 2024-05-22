# How to modify the commit message?

## single modify

- git commit --amend

## batch modify

- git rebase commit_id^
  - commit_id is the earliest commit you did.
  - replace `pick` with `edit`.
- git commit --amend [--author="AuthorName <email@address.com>"]
  - modify the message in vim editor.
- git rebase --continue
  - continue to modify the next commit.
