using UnityEngine;
using System.Collections;

public class CameraDrag : MonoBehaviour
{
  public Transform target;
  public float rotSpeed = 100;
  public float zoomSpeed = 100;
  Camera localCamera;

  float rotX = 0;
  float rotY = 0;

  float deltaX;
  float deltaY;

  float zoom = -10;
  public float zoomShift = -0.15f;
  float cameraY;

  bool autoRotate = false;

  void Start()
  {
    localCamera = GetComponentInChildren<Camera>();
    cameraY = localCamera.transform.localPosition.y;
    rotX = 25;
    rotY = 0;
    transform.localRotation = Quaternion.Euler(rotX, rotY, 0);
    localCamera.transform.localPosition = new Vector3(zoom * zoomShift, cameraY, zoom);
  }

  void Update()
  {
    if (Input.GetMouseButton(0))
    {
      deltaX = Input.GetAxis("Mouse Y") * rotSpeed;
      deltaY = Input.GetAxis("Mouse X") * rotSpeed;
      rotX -= deltaX * Time.deltaTime;
      rotY += deltaY * Time.deltaTime;
      transform.rotation = Quaternion.Euler(rotX, rotY, 0);
      if (deltaX + deltaY > 5)
      {
        autoRotate = true;
      }
    }
    if (autoRotate)
    {
      rotX -= deltaX * Time.deltaTime * 0.4f;
      rotY += deltaY * Time.deltaTime * 0.4f;
      transform.rotation = Quaternion.Euler(rotX, rotY, 0);
    }
    float wheel = Input.GetAxis("Mouse ScrollWheel");
    if (wheel != 0)
    {
      zoom += -wheel * zoom * zoomSpeed * Time.deltaTime;
      zoom = Mathf.Clamp(zoom, -35, -3);
      localCamera.transform.localPosition = new Vector3(zoom * zoomShift, cameraY, zoom);
    }
  }
}
