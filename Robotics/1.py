import roboticstoolbox as rtb
robot = rtb.models.Panda()
print(robot)

Te = robot.fkine(robot.qr)  # forward kinematics
print(Te)

from spatialmath import SE3

Tep = SE3.Trans(0.6, -0.3, 0.1) * SE3.OA([0, 1, 0], [0, 0, -1])
sol = robot.ik_lm_chan(Tep)         # solve IK
print(sol)
 
q_pickup = sol[0]
print(robot.fkine(q_pickup))    # FK shows that desired end-effector pose was achieved

qt = rtb.jtraj(robot.qr, q_pickup, 50)
robot.plot(qt.q, backend='pyplot', movie='panda1.gif')

robot.plot(qt.q)

import swift
import roboticstoolbox as rp
import spatialmath as sm
import numpy as np

env = swift.Swift()
env.launch(realtime=True)

panda = rp.models.Panda()
panda.q = panda.qr

Tep = panda.fkine(panda.q) * sm.SE3.Trans(0.2, 0.2, 0.45)

arrived = False
env.add(panda)

dt = 0.05

while not arrived:

    v, arrived = rp.p_servo(panda.fkine(panda.q), Tep, 1)
    panda.qd = np.linalg.pinv(panda.jacobe(panda.q)) @ v
    env.step(dt)

# Uncomment to stop the browser tab from closing
# env.hold()