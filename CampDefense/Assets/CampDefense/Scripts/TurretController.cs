using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TurretController : MonoBehaviour
{
    public float attackInterval = 1.5f;
    private float attackTimer = 0.0f;

    public float damagePerAttack = 25.0f;

    private List<EnemyController> enemies = new List<EnemyController>();

    [SerializeField]
    private Transform weaponTransform;

    private void FixedUpdate()
    {
        attackTimer += Time.deltaTime;
        if(enemies.Count > 0)
        {
            EnemyController enemyTarget = enemies[0];
            Vector3 offsetToEnemy = enemyTarget.transform.position - transform.position;
            weaponTransform.rotation = Quaternion.LookRotation(offsetToEnemy.normalized, Vector3.up);

            // time to attack?
            if (attackTimer > attackInterval)
            {
                Debug.DrawLine(transform.position, enemyTarget.transform.position, Color.red);
                enemyTarget.TakeDamage(damagePerAttack);

                attackTimer = 0.0f;
            }
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.TryGetComponent<EnemyController>(out var enemy))
        {
            enemy.OnDeath.AddListener(HandleEnemyDeath);
            enemies.Add(enemy);
        }
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.TryGetComponent<EnemyController>(out var enemy))
        {
            enemy.OnDeath.RemoveListener(HandleEnemyDeath);
            enemies.Remove(enemy);
        }
    }

    private void HandleEnemyDeath(EnemyController enemy)
    {
        enemies.Remove(enemy);
    }
}
