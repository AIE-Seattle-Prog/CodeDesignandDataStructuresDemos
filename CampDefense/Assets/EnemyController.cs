using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyController : MonoBehaviour
{
    [SerializeField]
    private float health = 100;

    public void TakeDamage(float damageDealt)
    {
        health -= damageDealt;
    }
}
