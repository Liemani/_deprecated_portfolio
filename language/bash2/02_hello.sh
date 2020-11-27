echo '#!/bin/sh' > my-script.sh
echo 'echo Hello World' >> my-script.sh
cat my-script.sh
chmod 755 my-script.sh
# Note that to make a file excutable, you must set the eXecutable bit,
# and for a shell script, the Readable bit must also be set
# chmod a+rx my-script.sh
./my-script.sh
