# How to exchange the order of serveral commits?

- git rebase -i [commit_id | --root | HEAD~n]
  - meaning of [commit_id, root, HEAD~n] refers to [02-squash](./02-squash-multiple-commits.md)
- after that, a vim editor interface will appear.
- change the `pick` lines' order to you want.