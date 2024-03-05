<?php
/* Imagine a lot of code here */ 
$very_bad_unclear_name = "15 chicken wings";

// Write your code here:


// 1 пункт

// Ссылка как в C и C++
$order = &$very_bad_unclear_name;

// Конкатенация через .
$order.=", two number 9s, a number 9 large, a number 6 with extra dip, a number 7, two number 45s, one with cheese, and a large soda";
  
// Don't change the line below
echo "\nYour order is: $very_bad_unclear_name.";

echo "\n\n";


// 2 пункт

$x = 420;

echo "int = $x";

echo "\n";

$f = 19.8588925893205832953839;

echo "float = $f\n";

$g = 96 / 8;

echo "twelve = $g\n";

$last_month = 1187.23;

$this_month = 1089.98;

echo "difference = ", $last_month - $this_month, "\n\n";


// 11 пункт (3 пункт?)

$num_languages = 4;

$months = 11;

$days = 16 * $months;

$days_per_language = $days / $num_languages;

echo "days per language = $days_per_language\n\n";


// 12 пункт

echo "8^2 = ", 8**2, "\n\n";


// 13 пункт

$my_num = 24;

$answer = $my_num;

$answer += 2;

$answer *= 2;

$answer -= 2;

$answer /= 2;

$answer -= $my_num;

echo "answer = $answer\n\n";


// 14 пункт

$a = 10;

$b = 3;

$r = $a % $b;

echo "a%b = ", $r, "\n";

// if оператор тоже как в C
if ($a % $b == 0) {
	echo "Делится\n";
}
else {
	echo "Делится с остатком $r\n";  
}

$st = pow(2, 10);

echo "2^10 = $st\n";

$sq = sqrt(245);

echo "245^0.5 = $sq\n";

$ls = [4, 2, 5, 19, 13, 0, 10];

$res = 0;

// foreach как в Питоне for i in ls 
foreach ($ls as $i) {
	$res += pow($i, 2);
}

$res = sqrt($res);

echo "корень суммы квадратов = $res\n";

$sq379 = sqrt(379);

$val1 = round($sq379);

echo "округление 379^0.5 до целых = $val1\n";

$val01 = round($sq379, 1);

echo "	 до десятых = $val01\n";

$val001 = round($sq379, 2);

echo "	 до сотых = $val001\n";

$sq587 = sqrt(587);

$arr = [];

$arr['floor'] = floor($sq587);

$arr['ceil'] = ceil($sq587);

$o1 = $arr['ceil'];

$o2 = $arr['floor'];

echo "округление 587^0.5 в большую сторону = $o1\n";
echo "округление 587^0.5 в меньшую сторону = $o2\n";

$num_arr = [4, -2, 5, 19, -130, 0, 10];

$min_num = min($num_arr);

echo "min = $min_num\n";

$max_num = max($num_arr);

echo "max = $max_num\n";

echo "random number = ", rand(0, 10), "\n";

$rand_arr = [];

// Цикл for буквально как в C
for ($i = 0; $i < 10; $i++) {
	array_push($rand_arr, rand());
}

echo "random array:\n";

foreach ($rand_arr as $i) {
	echo "$i ";
}

$a = 789;

$b = 1500;

$mod = abs($a - $b);

echo "\nabs(a - b) = $mod\n";

$num_arr2 = [1, 2, -1, -2, 3, -3];

$abs_arr = [];

foreach ($num_arr2 as $i) {
	array_push($abs_arr, abs($i));
}

$num = 30;

$divisors = [1];

for ($i = 2; $i < $num / 2 + 1; $i++) {
	if ($num % $i == 0) {
		array_push($divisors, $i);
	}
}

array_push($divisors, $num);

echo "все делители числа $num:\n";

foreach ($divisors as $i) {
	echo "$i ";
}

$num_arr3 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

$i = 0;

$sum = 0;

while ($sum < 10) {
	$sum += $num_arr3[$i];
	$i++;
}

echo "\nчтобы сумма была больше 10, нужно сложить $i первых элементов\n\n";


// 15 пункт

function printStringReturnNumber() {
	echo "строка\n";
	return 100;
}

$my_num = printStringReturnNumber();

echo "значение функции = $my_num\n\n";


// 16 пункт


