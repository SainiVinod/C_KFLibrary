git add --all
git add .
echo -n "Enter Commit Text > "
read text
git commit -m "$text"
git push
