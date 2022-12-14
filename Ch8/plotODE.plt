set terminal png size 1280, 1280 font "Helvetica,30"
set output 'ODEComparisonPlot.png' 

set grid
set xrange [0:1]
set xlabel 'x'
set ylabel ' y'
set title "Solution to the ODE y'=yx^2 with y(0)=1 and x in [0,1]"

plot 'Euler.dat' title "Euler" w lp dt "--_", 'RK4.dat' title "RK4" w p , 'exact.dat' title "exact" w l
