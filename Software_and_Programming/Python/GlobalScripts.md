# Global Python Scripts

A VERY useful link is this one here:

<http://askubuntu.com/questions/590410/how-do-i-run-python-code-as-a-script>

But I shall copy it here in md and the PDF copy of the forum response is also in the repo in the unlikely event that the forum deletes it. Full references and thanks Jacob Vlijm Feb 26 2015

### python /path/to/script.py

- works if file is either executable or not
- shebang (#!/usr/bin/env python) in the head of the script is good practice, but not needed

### /path/to/script.py
- works if script is executable
- shebang is needed (#!/usr/bin/env python)

### script.py
- works if script is in $PATH
- script needs to be executable
- filename needs to have extension
- shebang is needed (#!/usr/bin/env python)


### script
- works if script is in $PATH
- script needs to be executable
- filename should have no extension
- shebang is needed (#!/usr/bin/env python)
