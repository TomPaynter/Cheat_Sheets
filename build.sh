#!/bin/bash

# Print out the usage information and then quit
function help() {
  echo "A hack script for working with mdbook :)"
  echo
  echo "USAGE: ./build.sh build"
  echo "USAGE: ./build.sh serve"
  echo "USAGE: ./build.sh [-h|--help]"
  exit 1
}

# Check dependencies, then build the book
function build() {
  check_dependencies
  echo "Building..."
  mdbook build
}

# Check dependencies, then serve on http://localhost:3000/
# This also watches for changes and re-compiles automatically
function serve() {
  check_dependencies
  mdbook serve
}

# Check that you have mdbook installed. If you don't, Print
# out instructions for the user
function check_dependencies() {
  if hash mdbook 2>/dev/null; then
    return 0
  else
    echo "mdbook isn't installed"
    echo "to install it, you will need the rust compiler."
    echo 'run: `curl https://sh.rustup.rs -sSf | sh`'
    echo 'then run `cargo install mdbook`'
    exit 1
  fi
}


# Parse command line args
case "$1" in
  build )
    build
    ;;
  serve )
    serve
    ;;
  * )
    help
    ;;
esac

exit 0
