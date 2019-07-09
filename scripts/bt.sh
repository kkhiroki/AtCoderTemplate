task=$1
rootdir=/Users/hiroki/AtCoderDev
grep -v "WiilBeRemovedWhenSubmit" "${rootdir}/main.cpp" > "${rootdir}/main_rmv_ifstream.cpp"
g++ -std=gnu++1y -O2 -o "${rootdir}/work/${task}/a.out" "${rootdir}/main_rmv_ifstream.cpp"
cd "${rootdir}/work/${task}"
oj test
cd $rootdir
cat ./main_rmv_ifstream.cpp | pbcopy
