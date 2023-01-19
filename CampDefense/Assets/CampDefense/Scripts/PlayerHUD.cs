using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class PlayerHUD : MonoBehaviour
{
    [SerializeField]
    private TMP_Text enemiesRemainingLabel;
    public string enemiesRemainingFormatter = "{0}";

    [SerializeField]
    private EnemySpawner spawner;
    [SerializeField]
    private CampsiteController campsite;

    void Update()
    {
        enemiesRemainingLabel.text = string.Format(enemiesRemainingFormatter, spawner.ActiveEnemyCount);
    }
}
