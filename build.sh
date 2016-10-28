#!/bin/bash

# Print out the usage information and then quit
function help() {
  echo "A hack script for working with mdbook :)"
  echo
  echo "USAGE: ./build.sh build"
  echo "       ./build.sh serve"
  echo "       ./build.sh travis"
  echo "       ./build.sh [-h|--help]"
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


function travis() {
  # instructions for integrating with travis-ci
  echo "0. Sign in to Travis CI with your GitHub account, accepting"
  echo "   the GitHub access permissions confirmation and syncing your account."
  echo "1. Make sure you have a ' gh-pages' branch"
  echo "2. Create a new GitHub API token"
  echo "3. Encrypt the token using the 'travis' ruby gem (gem install travis)"
  echo "4. Copy/Paste the token into the '- secure' bit at the bottom of"
  echo "   your '.travis.yml' file"
  echo
  echo "Instructions mostly copied from here:"
  echo "    https://github.com/steveklabnik/automatically_update_github_pages_with_travis_example#find-out-your-github-api-token"
  echo
  echo "To view your build progress, go to: https://travis-ci.org/"
  echo "Your stuff should be visible at https://<your-github-username>.github.io/<repo-name>/"
}

# Parse command line args
case "$1" in
  build )
    build
    ;;
  serve )
    serve
    ;;
  travis )
    travis
    ;;
  * )
    help
    ;;
esac

exit 0
