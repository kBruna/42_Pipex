set follow-fork-mode child
set detach-on-fork off
b main
r infile "sleep(1)" "wc -l" outfile
set logging enable on
backtrace
info locals
