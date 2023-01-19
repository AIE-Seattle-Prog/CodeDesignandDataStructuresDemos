using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TurretController : MonoBehaviour
{
    public float attackInterval = 1.5f;
    private float attackTimer = 0.0f;

    List<EnemyController> enemies = new List<EnemyController>();

    public float damagePerAttack = 25.0f;

    private void FixedUpdate()
    {
        attackTimer += Time.deltaTime;
        if(attackTimer > attackInterval &&
           enemies.Count > 0)
        {
            enemies[0].TakeDamage(damagePerAttack);
            attackTimer = 0.0f;

            Debug.DrawLine(transform.position, enemies[0].transform.position, Color.red);
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.TryGetComponent<EnemyController>(out var enemy))
        {
            enemies.Add(enemy);
        }
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.TryGetComponent<EnemyController>(out var enemy))
        {
            enemies.Remove(enemy);
        }
    }
}
