from deepface import DeepFace
import cv2
import matplotlib.pyplot as plt

# Open a connection to the camera (0 is usually the default camera)
cap = cv2.VideoCapture(0)

while True:
    # Capture a frame from the camera
    ret, frame = cap.read()

    # Display the captured frame

    plt.imshow(frame[:, :, ::-1])
    plt.show()

    # Analyze emotions in the current frame using DeepFace
    result = DeepFace.analyze(frame, actions=['emotion'])

    # Print the analysis result
    print(result)

    # Break the loop if 'q' key is pressed
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the camera and close all windows
cap.release()
cv2.destroyAllWindows()