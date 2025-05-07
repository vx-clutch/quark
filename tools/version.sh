#!/bin/sh

major_version="0.0"
tag="alpha"

if test -d .git ; then
if type git >/dev/null 2>&1 ; then
  printf "%s.%s-%s" $major_version "$(git rev-list --count HEAD)" $tag > version
fi
else
cat version
fi
