using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    [SerializeField]
    private GameObject[] turretPrefabs;
    private int currentTurretIndex = -1;

    [SerializeField]
    private CameraController cameraController;
    [SerializeField]
    private LayerMask pickerMask = ~1;

    private void Update()
    {
        if (Input.GetButtonDown("Cancel"))
        {
            currentTurretIndex = -1;
        }
        else if (Input.GetButtonDown("Turret1"))
        {
            currentTurretIndex = 0;
        }
        else if (Input.GetButtonDown("Turret2"))
        {
            currentTurretIndex = 1;
        }
        else if (Input.GetButtonDown("Turret3"))
        {
            currentTurretIndex = 2;
        }

        // early exit - no picking work to do
        if(currentTurretIndex == -1) { return; }

        Ray pickerRay = cameraController.TargetCamera.ScreenPointToRay(Input.mousePosition);
        if(Physics.Raycast(pickerRay, out var hitInfo, Mathf.Infinity, pickerMask))
        {
            Vector3 turretPos = hitInfo.collider.transform.position;
            turretPos.y = hitInfo.point.y;

            Debug.DrawRay(turretPos, Vector3.up, Color.red);

            if (Input.GetButtonDown("Fire1"))
            {
                Instantiate(turretPrefabs[currentTurretIndex], turretPos, Quaternion.identity);
            }
        }
    }
}
