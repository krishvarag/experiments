#!/usr/bin/env bash

# Enable Exit on error
set -e


# Traps 
# Define error handler and associate to trap
function clenup()
{
	echo "[$$]: cleanup operation ......"
}
function error_handler()
{
	last_cmd=${BASH_COMMAND}
	error_code=$?
	if [[ $? -ne 0 ]]; then
	echo "An error occurred. Exiting..." >&2
	echo "$last_cmd" >&2
	fi
	clenup
	return $error_code
}
trap error_handler EXIT

# Helper
function script_details()
{
    #echo $0
	echo "*********************************************"
	PARENT=${0%/*}
	fn=${0##*/}
    fn_no_ext=${fn%.*}
	echo "Source : $BASH_SOURCE"
	#echo $(basename $(readlink -nf $0))
	echo "PID    : $$"
	echo "PARENT  : $PARENT"
	echo "FileName    : $fn"
	echo "FileName (no extension)    : $fn_no_ext"
	echo "*********************************************"
}
# Main code 
script_details
echo  "Hello Line1"
# simulate error
echo1 "Hello L2"
echo  "Hello L3"
