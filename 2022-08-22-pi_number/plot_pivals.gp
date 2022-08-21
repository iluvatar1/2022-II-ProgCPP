set log xy
set xlabel "Iter"
set ylabel "Relative difference"
plot "pivals.txt" u 1:3 w lp pt 4 lw 2 t 'numerical data'
set term pdf
set out "pivals.pdf"
replot
