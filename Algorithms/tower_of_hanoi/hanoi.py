"""
This is implemented using Phidias library
https://github.com/corradosantoro/phidias

"""


from phidias.Main import *
from phidias.Lib import *

class hanoi(Procedure): pass
class tower(Belief): pass


def_vars('N','source','auxiliary','target')



hanoi(N, source, target, auxiliary) / gt(N,0)>> \
 [
 'N = N-1',
 hanoi(N, source, auxiliary, target),
 show_line('Moving ', N, ' da ', source, ' in ',auxiliary),
 -tower(N,source),
 hanoi(N, auxiliary, target, source),
 show_line('Moving ', N, ' da ', auxiliary, ' in ', target),
 +tower(N,target)
 ]




# instantiate the engine
PHIDIAS.run()
# run the engine shell
PHIDIAS.shell(globals())


