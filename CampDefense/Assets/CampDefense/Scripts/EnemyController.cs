using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;
using UnityEngine.Events;

public class EnemyController : MonoBehaviour
{
    [SerializeField]
    private float health = 100;
    public float Health
    {
        get => health;
        private set => health = value;
    }
    public bool IsAlive => Health > 0;

    [field: SerializeField]
    public UnityEvent<EnemyController> OnDeath { get; private set; } = new UnityEvent<EnemyController>();

    [SerializeField]
    private NavMeshAgent navAgent;

    private LinkedListNode<EnemyController> spawnerNode;

    public float CampsiteDamage = 5.0f;

    public void TakeDamage(float damageDealt)
    {
        health -= damageDealt;
        if (health < 0)
        {
            Death();
        }
    }

    public void Kill()
    {
        Death();
    }

    public void SetSpawnerNode(LinkedListNode<EnemyController> spawnerNode)
    {
        this.spawnerNode = spawnerNode;
    }

    private void Death()
    {
        // remove self from spawner if applicable
        if (spawnerNode != null)
        {
            spawnerNode.List.Remove(spawnerNode);
        }

        // set to zero or lower
        Health = Mathf.Min(Health, 0);

        OnDeath?.Invoke(this);

        Destroy(gameObject);
    }

    private void Start()
    {
        navAgent.SetDestination(CampsiteController.Instance.transform.position);
    }
}
