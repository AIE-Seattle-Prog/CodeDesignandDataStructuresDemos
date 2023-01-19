using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemySpawner : MonoBehaviour
{
    public GameObject enemyPrefab;

    public float spawnInterval = 1.0f;
    private float spawnTimer = 0.0f;

    public int spawnQuota = 20;
    private int spawnProgress = 0;

    private LinkedList<EnemyController> enemies = new LinkedList<EnemyController>();
    public int ActiveEnemyCount => enemies.Count;

    void FixedUpdate()
    {
        spawnTimer += Time.deltaTime;
        if(spawnTimer > spawnInterval &&
            spawnProgress < spawnQuota)
        {
            GameObject newEnemy = Instantiate(enemyPrefab, transform.position, transform.rotation);
            
            bool spawnValid = newEnemy.TryGetComponent<EnemyController>(out var enemy);
            Debug.Assert(spawnValid, "Enemy prefab is missing its controller!");

            enemy.SetSpawnerNode(enemies.AddLast(enemy));

            spawnTimer = 0.0f;
            ++spawnProgress;
        }
    }
}
