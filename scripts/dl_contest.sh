contest=$1

work=/Users/hiroki/AtCoderDev/work
rm -rf $work
mkdir $work
cd $work

url_base="https://atcoder.jp/contests/${contest}/tasks/${contest}"

echo $url_base

for t in a b c d e f; do
	url="${url_base}_${t}"
	echo "now downloading... ${url}"
	oj dl $url
	mkdir $t
	mv ./test "./${t}/test"
done
