using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraController : MonoBehaviour
{
    public float panSpeed = 3.0f;
    public float zoomMin = -5.0f;
    public float zoomMax = 5.0f;
    public float zoomSpeed = 2.0f;
    private float zoomLevel = 0.0f;

    public Transform cameraTransform;

    void Update()
    {
        Vector3 playerInput = new Vector3(Input.GetAxisRaw("Horizontal"), 0.0f, Input.GetAxisRaw("Vertical"));

        playerInput = Vector3.ClampMagnitude(playerInput, 1.0f);
        playerInput = Quaternion.AngleAxis(transform.rotation.eulerAngles.y, Vector3.up) * playerInput;

        float zoomDelta = -Input.mouseScrollDelta.y * zoomSpeed;
        zoomLevel += zoomDelta;
        zoomLevel = Mathf.Clamp(zoomLevel, zoomMin, zoomMax);

        transform.position += playerInput * panSpeed * Time.deltaTime;
        cameraTransform.localPosition = Vector3.forward * zoomLevel;
    }
}
