set terminal pngcairo enhanced font "Arial,12" size 1200,800
set output "sorting_times.png"

set title "Зависимость времени сортировки от размера массива"
set xlabel "Размер массива (N)"
set ylabel "Время (наносекунды)"
set logscale xy  # Логарифмическая шкала (удобно для больших диапазонов)
set grid

set key top left

plot "sorting_times.dat" using 1:2 with linespoints title "Bubble Sort", \
     "" using 1:3 with linespoints title "Insertion Sort", \
     "" using 1:4 with linespoints title "Selection Sort", \
     "" using 1:5 with linespoints title "Quick Sort", \
     "" using 1:6 with linespoints title "Merge Sort"
