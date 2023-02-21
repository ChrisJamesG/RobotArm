import keyboard
import serial
import sys

def sendInputs(ser):
    # set the key that triggers the servo movement
    rotate_shoulder_left_key = 'a'
    rotate_shoulder_right_key = 'd'
    rotate_shoulder_back_key = 's'
    rotate_shoulder_forward_key = 'w'
    rotate_forearm_up_key = 'e'
    rotate_forearm_down_key = 'q'

    # key-servo map
    key_servo_map = {
        rotate_shoulder_left_key : '1',
        rotate_shoulder_right_key : '2',
        rotate_shoulder_back_key : '3',
        rotate_shoulder_forward_key : '4',
        rotate_forearm_up_key : '5',
        rotate_forearm_down_key : '6'
    }

    # continuously send serial data while the key is being held down
    while True:
        for key, servo_signal in key_servo_map.items():
            if keyboard.is_pressed(key):
                ser.write(servo_signal.encode())  # send the servo signal as serial data
                print("Pressing " + key)
            else:
                ser.write(b'0')  # send the value '0' as serial data

def main():
    ser = serial.Serial('COM3', 9600)
    sendInputs(ser)

if __name__ == '__main__':
    main()