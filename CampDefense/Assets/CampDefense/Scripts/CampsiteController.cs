using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Events;

public class CampsiteController : MonoBehaviour
{
    public static CampsiteController Instance { get; private set; }

    private float health = 20.0f;
    public float Health
    {
        get => health;
        private set => health = value;
    }

    [field: SerializeField]
    public UnityEvent OnDeath { get; private set; } = new UnityEvent();

    private void Awake()
    {
        Debug.Assert(Instance == null, "More than one Campsite exists! Not OK!");
        Instance = this;
    }

    public void TakeDamage(float damage)
    {
        Health -= damage;
        if(Health < 0)
        {
            OnDeath?.Invoke();
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        if(other.TryGetComponent<EnemyController>(out var enemy))
        {
            TakeDamage(enemy.CampsiteDamage);
            enemy.Kill();
        }
    }
}
