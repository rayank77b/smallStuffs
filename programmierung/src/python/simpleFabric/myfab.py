#!/usr/bin/python
#
# this is a simple example of first init of fabric,
# see https://github.com/fabric/fabric/commit/1efaddf0aed522f1d772e894afa1abb6cd622414
#
# this is only for learning purpose

import types

COMMANDS = {}


def run(cmd):
    "This is the command, which will be executed, with argument cmd"
    print "we run: %s"%cmd

def run2(cmd):
    "This is the command, which will be executed, with argument cmd"
    print "we run2: %s"%cmd

def load(filename):
    "Load up the given fabfile."
    execfile(filename)             # execute the my.fabfile.py
    for name, obj in locals().items():  # on all functions/objects we have
        # search only for not __bla__ and functions not variables/objects
        if not name.startswith('_') and isinstance(obj, types.FunctionType):
            COMMANDS[name] = obj   # store it ;)

def _list_objs(objs):
    max_name_len = reduce(lambda a,b: max(a, len(b)), objs.keys(), 0)
    print "_list_objs(): max_name_len: ",max_name_len
    cmds = objs.items()
    cmds.sort(lambda x,y: cmp(x[0], y[0]))
    print cmds
    for name, fn in cmds:
        print '  ', name.ljust(max_name_len), ':', fn.__doc__.splitlines()[0]


def main():
    fabfile = "my.fabfile.py"
    load(fabfile)
    _list_objs(COMMANDS)
    # we execute all commands from fabfile
    for cmd in ('myFunc1', 'myFunc2', 'myFunc1'): # the list which command we sill execute
        COMMANDS[cmd]()

if __name__ == '__main__':
    main()

