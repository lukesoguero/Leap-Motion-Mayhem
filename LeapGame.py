import Leap, sys, thread, time, serial
sys.path.append("/usr/lib/Leap")
sys.path.append("/path/to/lib/x86")
sys.path.append("/path/to/lib")


class SampleListener(Leap.Listener):
    finger_names = ['Thumb', 'Index', 'Middle', 'Ring', 'Pinky']
    bone_names = ['Metacarpal', 'Proximal', 'Intermediate', 'Distal']
    ser = serial.Serial('COM4', 9600)
    frame_cnt = 0

    def on_init(self, controller):
        print "Initialized"

    def on_connect(self, controller):
        print "Connected"

    def on_disconnect(self, controller):
        print "Disconnected"

    def on_exit(self, controller):
        print "Exited"

    def on_frame(self, controller):
        # Get the most recent frame and report some basic information
        frame = controller.frame()
        self.frame_cnt += 1

        if self.frame_cnt % 15 == 0:

            # Get hands
            for hand in frame.hands:

                normal = hand.palm_normal
                direction = hand.direction

                shooting = False
                extended = frame.fingers.extended()
                if len(extended) == 4:
                    shooting = True

                blocking = False
                if (direction.pitch * Leap.RAD_TO_DEG) > 40:
                    blocking = True


                # Calculate the hand's pitch, roll, and yaw angles
                print "  pitch: %f degrees, roll: %f degrees, yaw: %f degrees" % (
                    direction.pitch * Leap.RAD_TO_DEG,
                    normal.roll * Leap.RAD_TO_DEG,
                    direction.yaw * Leap.RAD_TO_DEG)

                if ((direction.yaw * Leap.RAD_TO_DEG) < -29) and ((direction.yaw * Leap.RAD_TO_DEG) > -45) and shooting:
                    self.sendHandInfo('a')
                if ((direction.yaw * Leap.RAD_TO_DEG) < -15.25) and ((direction.yaw * Leap.RAD_TO_DEG) > -29) and shooting:
                    self.sendHandInfo('b')
                if ((direction.yaw * Leap.RAD_TO_DEG) < -2.75) and ((direction.yaw * Leap.RAD_TO_DEG) > -15.25) and shooting:
                    self.sendHandInfo('c')
                if ((direction.yaw * Leap.RAD_TO_DEG) < 7.5) and ((direction.yaw * Leap.RAD_TO_DEG) > -2.75) and shooting:
                    self.sendHandInfo('d')
                if ((direction.yaw * Leap.RAD_TO_DEG) < 22) and ((direction.yaw * Leap.RAD_TO_DEG) > 7.5) and shooting:
                    self.sendHandInfo('e')
                
                if blocking:
                    print "blocking"
                    self.sendHandInfo('g')


    def sendHandInfo(self, info):
        self.ser.write(info.encode())



def main():
    # Create a listener and controller
    listener = SampleListener()
    controller = Leap.Controller()

    # Have the listener receive events from the controller
    controller.add_listener(listener)

    print "Press Enter to quit..."
    try:
        sys.stdin.readline()
    except KeyboardInterrupt:
        pass
    finally:
        # Remove the listener when done
        controller.remove_listener(listener)


if __name__ == "__main__":
    main()
