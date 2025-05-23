set terminal pngcairo enhanced font "Arial,12" size 1200,800
set output "sorting_times.png"

set title "Зависимость размера массива от времени сортировки"
set xlabel "Время (наносекунды)"
set ylabel "Размер массива (N)"
set logscale xy
set grid

set key top right

plot "sorting_times.dat" using 2:1 with linespoints title "Bubble Sort", \
     "" using 3:1 with linespoints title "Insertion Sort", \
     "" using 4:1 with linespoints title "Selection Sort", \
     "" using 5:1 with linespoints title "Quick Sort", \
     "" using 6:1 with linespoints title "Merge Sort"
