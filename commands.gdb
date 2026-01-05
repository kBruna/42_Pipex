set follow-fork-mode child
set detach-on-fork off
b main
r Makefile " " " " outfile_no_w
backtrace
info locals
