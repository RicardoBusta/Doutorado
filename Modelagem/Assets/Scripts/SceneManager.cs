using UnityEngine;

public class SceneManager : MonoBehaviour
{
    static SceneManager instance;

    void Awake()
    {
        instance = this;
    }

    public static SceneManager GetInstance()
    {
        return instance;
    }
}
