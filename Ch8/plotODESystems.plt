set terminal png size 2000, 2000 font "Helvetica,30"
set output 'ODESytems.png' 

set multiplot layout 2,1 rowsfirst

set grid
set xlabel 'u'
set ylabel ' v'
set yrange [-10:10]
set title "Solution to the ODE system: u'=v and v'= -kv-u^3+Bcos(t) with u(0)=v(0)=1 and t in [0,100]

plot  'ODESystemCase1.dat' title "k=0.1 and B=11.0" w l
plot  'ODESystemCase2.dat' title "k=0.4 and B=20.0" w l

unset multiplot
