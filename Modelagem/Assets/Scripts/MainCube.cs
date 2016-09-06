using UnityEngine;
using UnityEngine.UI;

public class MainCube : MonoBehaviour
{
    public GameObject cubePrefab;
    public GameObject interrogationPrefab;
    public Dropdown cubeSizeDropDown;
    public int cubeMode;

    public bool[,,] cubeGrid;
    public GameObject[,,] cubeObjGrid;
    public int gridSize;

    public void CubeValueChanged()
    {
        switch (cubeSizeDropDown.value)
        {
            case 0:
                transform.localScale = new Vector3(1, 1, 1);
                CreateCube(0);
                break;
            case 1:
                transform.localScale = new Vector3(1, 1, 1);
                CreateCube(4);
                break;
            case 2:
                transform.localScale = new Vector3(0.5f, 0.5f, 0.5f);
                CreateCube(8);
                break;
            case 3:
                transform.localScale = new Vector3(0.25f, 0.25f, 0.25f);
                CreateCube(16);
                break;
        }
    }

    public void CubeModeChanged(int mode)
    {
        cubeMode = mode;
    }

    void CreateCube(int value)
    {
        while (transform.childCount > 0)
        {
            DestroyImmediate(transform.GetChild(0).gameObject);
        }
        if (value < 1)
        {
            GameObject g = (GameObject)Instantiate(interrogationPrefab, Vector3.zero, Quaternion.identity);
            g.transform.SetParent(transform, true);
            return;
        }
        gridSize = value;
        cubeGrid = new bool[value, value, value];
        cubeObjGrid = new GameObject[value, value, value];
        float shift = (value / 2.0f) - 0.5f;
        Vector3 shiftV = new Vector3(shift, shift, shift);
        for (int i = 0; i < value; i++)
        {
            for (int j = 0; j < value; j++)
            {
                for (int k = 0; k < value; k++)
                {
                    Vector3 pos = new Vector3(i, j, k);
                    cubeGrid[i, j, k] = true;
                    GameObject g = (GameObject)Instantiate(cubePrefab);
                    cubeObjGrid[i, j, k] = g;
                    g.transform.SetParent(transform, true);
                    g.transform.localScale = new Vector3(1, 1, 1);
                    g.transform.localPosition = pos - shiftV;
                    CubeCast c = g.GetComponent<CubeCast>();
                    c.mainCube = this;
                    c.coords = pos;
                }
            }
        }
    }
}