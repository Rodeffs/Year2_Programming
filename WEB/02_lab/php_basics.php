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

echo "\n";


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

echo $last_month - $this_month, "\n";


// 11 пункт (3 пункт?)

$num_languages = 4;

$months = 11;

$days = 16 * $months;

$days_per_language = $days / $num_languages;

echo "days per language = $days_per_language\n";
