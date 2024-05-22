# How to squash multiple commits into one?

- git rebase -i [commit_id | --root | HEAD~n]
  - commit_id: if you want rebase to commid_id 39cd959, you should use 39cd959~(39cd959's previous commit)
  - --root: if you want to rebase all the commit to first commit, use it.
  - HEAD~n: if you want to squash 3 commits into 1 commit, then n = 3.
- replace `pick` with `squash`
- then ammend the commit message


rebase theory

- if you want to manipulate the 3 most recent commits, you need to find the base of these 3 commits, which is the 4th commit counting backward, denoted as `-i HEAD~3`.