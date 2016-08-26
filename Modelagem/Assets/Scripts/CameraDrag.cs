using UnityEngine;
using System.Collections;

public class CameraDrag : MonoBehaviour {
  public Transform target;
  public float speed = 5;
  public Camera camera;

  float rotX = 0;
  float rotY = 0;

  float deltaX;
  float deltaY;

  float zoom = -10;

  bool autoRotate = false;

  void Update() {
    if (Input.GetMouseButton(0)) {
      deltaX = Input.GetAxis("Mouse Y") * speed;
      deltaY = Input.GetAxis("Mouse X") * speed;
      rotX -= deltaX;
      rotY += deltaY;
      transform.rotation = Quaternion.Euler(rotX, rotY, 0);
      if (deltaX + deltaY > 5) {
        autoRotate = true;
      }
    }
    if (autoRotate) {
      rotX -= deltaX;
      rotY += deltaY;
      transform.rotation = Quaternion.Euler(rotX*0.4f, rotY*0.4f, 0);
    }
    float wheel = Input.GetAxis("Mouse ScrollWheel");
    if (wheel != 0) {
      zoom += -wheel*zoom;
      zoom = Mathf.Clamp(zoom, -35,-3);
      camera.transform.localPosition = new Vector3(0,0,zoom);
    }
  }
}
