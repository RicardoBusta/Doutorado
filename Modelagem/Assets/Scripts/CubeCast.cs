using UnityEngine;
using System.Collections;

public class CubeCast : MonoBehaviour
{
    const double clickTimer = 0.2;
    double timerMouseDown = 0;

    Vector3 clickPos;
    Vector3 mousePos;

    public MainCube mainCube;
    public Vector3 coords;

    void OnMouseDown()
    {
        timerMouseDown = Time.time;
        mousePos = Input.mousePosition;
    }
    void OnMouseUp()
    {
        if ((Input.mousePosition - mousePos).sqrMagnitude > 1)
        {
            return;
        }
        if (Time.time - timerMouseDown < clickTimer)
        {
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            RaycastHit hit;
            Physics.Raycast(ray, out hit, 100.0f);
            if (hit.collider == this.GetComponent<Collider>())
            {
                switch (mainCube.cubeMode)
                {
                    case 0: //create
                        Vector3 p = hit.point;

                        Debug.Log("Clicked on cube: " + coords);

                        // Calculate direction
                        Vector3 expandDirection = hit.normal;

                        Debug.Log("Expand dir: " + expandDirection);
                        Vector3 c = coords + expandDirection;
                        Debug.Log("Creating cube: " + c);
                        if (c.x >= 0 && c.x < mainCube.gridSize && c.y >= 0 && c.y < mainCube.gridSize && c.z >= 0 && c.z < mainCube.gridSize)
                        {
                            mainCube.cubeGrid[(int)c.x, (int)c.y, (int)c.z] = true;
                            mainCube.cubeObjGrid[(int)c.x, (int)c.y, (int)c.z].SetActive(true);
                        }

                        break;
                    case 1: //break
                        this.gameObject.SetActive(false);

                        Debug.Log("Breaking cube: " + coords);
                        break;
                    case 2: //select
                        break;
                }
            }
        }
    }
    void Update()
    {
        Debug.DrawLine(Vector3.zero, clickPos);
    }
}
