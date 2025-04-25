#!/usr/bin/env bash

# -------------------------------------------------------------------
#          Test & Comparison for ScalarConverter
# -------------------------------------------------------------------

# ANSI color codes
RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[0;33m"
BLUE="\033[0;34m"
RESET="\033[0m"

# Run a single test: compare expected vs actual
run_test() {
    local input="$1"
    local exp
    exp="$(expected "$input")"
    IFS=' ' read -r -a args <<< "$input"

    echo -e "${YELLOW}=== Test: '$input' ===${RESET}"
    echo -e "${GREEN}-- Expected --${RESET}"
    printf "%s\n" "$exp"
    echo -e "${GREEN}-- Actual --${RESET}"
    ./convert "${args[@]}"
    echo
}

# Define expected output for each literal
expected() {
  case "$1" in
    # wrong number of args
    ""|*\ *)
      echo "Not the right number of arguments"
      ;;
    # invalid literals
    hello|42..0)
      cat <<'EOF'
char: impossible
int: impossible
float: impossible
double: impossible
EOF
      ;;
    # char literals
    c)
      cat <<'EOF'
char: 'c'
int: 99
float: 99.0f
double: 99.0
EOF
      ;;
    '#')
      cat <<'EOF'
char: '#'
int: 35
float: 35.0f
double: 35.0
EOF
      ;;
    ' ')
      cat <<'EOF'
char: ' '
int: 32
float: 32.0f
double: 32.0
EOF
      ;;
    # int in range
    0)
      cat <<'EOF'
char: Non displayable
int: 0
float: 0.0f
double: 0.0
EOF
      ;;
    42)
      cat <<'EOF'
char: '*'
int: 42
float: 42.0f
double: 42.0
EOF
      ;;
    -42)
      cat <<'EOF'
char: Non displayable
int: -42
float: -42.0f
double: -42.0
EOF
      ;;
    2147483647)
      cat <<'EOF'
char: Non displayable
int: 2147483647
float: 2147483647.0f
double: 2147483647.0
EOF
      ;;
    -2147483648)
      cat <<'EOF'
char: Non displayable
int: -2147483648
float: -2147483648.0f
double: -2147483648.0
EOF
      ;;
    # int out of range
    2147483648|-2147483649)
      cat <<'EOF'
char: impossible
int: impossible
float: impossible
double: impossible
EOF
      ;;
    # normal floats
    0.0f)
      cat <<'EOF'
char: Non displayable
int: 0
float: 0.0f
double: 0.0
EOF
      ;;
    3.14f)
      cat <<'EOF'
char: Non displayable
int: 3
float: 3.14f
double: 3.14
EOF
      ;;
    -3.14f)
      cat <<'EOF'
char: Non displayable
int: -3
float: -3.14f
double: -3.14
EOF
      ;;
    42.000f)
      cat <<'EOF'
char: Non displayable
int: 42
float: 42.000f
double: 42.000
EOF
      ;;
    +0.5f)
      cat <<'EOF'
char: Non displayable
int: 0
float: 0.5f
double: 0.5
EOF
      ;;
    # float pseudo-literals
    nanf)
      cat <<'EOF'
char: impossible
int: impossible
float: nanf
double: nan
EOF
      ;;
    inff|\+inff)
      cat <<'EOF'
char: impossible
int: impossible
float: inff
double: inf
EOF
      ;;
    -inff)
      cat <<'EOF'
char: impossible
int: impossible
float: -inff
double: -inf
EOF
      ;;
    # normal doubles
    0.0)
      cat <<'EOF'
char: Non displayable
int: 0
float: 0.0f
double: 0.0
EOF
      ;;
    3.1415)
      cat <<'EOF'
char: Non displayable
int: 3
float: 3.1415f
double: 3.1415
EOF
      ;;
    -3.1415)
      cat <<'EOF'
char: Non displayable
int: -3
float: -3.1415f
double: -3.1415
EOF
      ;;
    42.000)
      cat <<'EOF'
char: Non displayable
int: 42
float: 42.000f
double: 42.000
EOF
      ;;
    +0.5)
      cat <<'EOF'
char: Non displayable
int: 0
float: 0.5f
double: 0.5
EOF
      ;;
    # double pseudo-literals
    nan)
      cat <<'EOF'
char: impossible
int: impossible
float: nanf
double: nan
EOF
      ;;
    inf|\+inf)
      cat <<'EOF'
char: impossible
int: impossible
float: inff
double: inf
EOF
      ;;
    -inf)
      cat <<'EOF'
char: impossible
int: impossible
float: -inff
double: -inf
EOF
      ;;
    # overflow tests
    99999999999)
      cat <<'EOF'
char: impossible
int: impossible
float: 1e+11f
double: 1e+11

EOF
      ;;
    # fallback
    *)
      echo "### No expected output defined for '$1'"
      ;;
  esac
}

# -------------------------------------------------------------------
#               Execute all test blocks
# -------------------------------------------------------------------

echo -e "${BLUE}=== Argument errors ===${RESET}"
run_test ""
run_test "a b"

echo
echo -e "${BLUE}=== Invalid literals ===${RESET}"
run_test "hello"
run_test "42..0"

echo
echo -e "${BLUE}=== Char literals ===${RESET}"
run_test "c"
run_test "#"
run_test " "

echo
echo -e "${BLUE}=== Int in range ===${RESET}"
run_test "0"
run_test "42"
run_test "-42"
run_test "2147483647"
run_test "-2147483648"

echo
echo -e "${BLUE}=== Int out of range ===${RESET}"
run_test "2147483648"
run_test "-2147483649"

echo
echo -e "${BLUE}=== Normal floats ===${RESET}"
run_test "0.0f"
run_test "3.14f"
run_test "-3.14f"
run_test "42.000f"
run_test "+0.5f"

echo
echo -e "${BLUE}=== Float pseudo-literals ===${RESET}"
run_test "nanf"
run_test "inff"
run_test "+inff"
run_test "-inff"

echo
echo -e "${BLUE}=== Normal doubles ===${RESET}"
run_test "0.0"
run_test "3.1415"
run_test "-3.1415"
run_test "42.000"
run_test "+0.5"

echo
echo -e "${BLUE}=== Double pseudo-literals ===${RESET}"
run_test "nan"
run_test "inf"
run_test "+inf"
run_test "-inf"

echo
echo -e "${BLUE}=== Overflow tests ===${RESET}"
run_test "99999999999"
